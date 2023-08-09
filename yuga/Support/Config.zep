namespace Yuga\Support;

use Countable;
use ArrayAccess;
use Traversable;
use JsonSerializable;
use IteratorAggregate;

class Config //implements ArrayAccess, Countable, IteratorAggregate, JsonSerializable
{
    protected data;
    protected defaultValue = null;
    
    public function load(file, key = null)
    {
        let file = str_replace(".", "/", file);
        let file = require Helpers::path(file.".php");

        if (key) {
            let this->data[key] = file;
        } else {
            let this->data = file;
        }
        
        return this;
    }

    public function get(key, defaultValue = null)
    {
        var segments, segment;
        if (empty(key)) {
            return this;
        }

        let this->defaultValue = defaultValue;
        let segments = explode('.', key);
        var data = this->data;
        for segment in segments {
            if (isset(data[segment])) {
                let data = data[segment];
            } else {
                let data = this->defaultValue;
                break;
            }
        }

        return data;
    }

    public function exists(key)
    {
        return this->get(key) !== this->defaultValue;
    }

    public function getAll()
    {
        return this->data;
    }

    public function set(key, value = null)
    {
        var data, segment, keyItem, valueItem;

        if (is_array(key)) {
            for keyItem, valueItem in key {
                this->set(keyItem, valueItem);
            }

            return this;
        }

        let data = this->data;
        
        for segment in explode('.', key) {

            if (!isset(data[segment]) || !is_array(data[segment])) {
                let data[segment] = [];
            }

            let data = data[segment];
        }

        let data = value;

        return this;
    }

    /**
     * Delete the given key or keys
     * @param array<TKey>|array<TKey, TValue>|int|string keys
     * @return Config
     */
    public function delete(keys)
    {
        var key;
        let keys = (array) keys;

        for (key in keys) {
            if (this->exists(key)) {
               unset(this->data[key]);

               continue;
            }

           var items = this->data, segment, segments, lastSegment;
           let segments = explode('.', key);
           let lastSegment = array_pop(segments);

            for (segment in segment) {
                if (!isset(items[segment]) || !is_array(items[segment])) {
                   continue;
                }

                let items = items[segment];
            }

           unset(items[lastSegment]);
        }

       return this;
    }

    /**
     * Return the value of a given key or all the values as JSON
     *
     * @param  mixed  key
     * @param  int  options
     * @return string|false
     */
    public function toJson(key = null, options = 0)
    {
        if (is_string(key)) {
            return json_encode(this->get(key), options);
        }

        let options = key;
        
        if key === null {
            let options = 0;
        }

        return json_encode(this->data, options);
    }

    /**
     * Check if a given key exists
     *
     * @param  int|string  key
     * @return bool
     */
    public function offsetExists(key)
    {
        return this->exists(key);
    }

    /**
     * Return the value of a given key
     *
     * @param  int|string  key
     * @return mixed
     */
    public function offsetGet(key)
    {
        return this->get(key);
    }

    /**
     * Set a given value to the given key
     *
     * @param int|string|null  key
     * @param mixed  value
     */
    public function offsetSet(key, value)
    {
        if (key === null) {
            let this->data[] = value;

            return;
        }

        // this->set(key, value);
    }

    /**
     * Delete the given key
     *
     * @param  int|string  key
     * @return void
     */
    public function offsetUnset(key)
    {
        this->delete(key);
    }

    /**
     * Return the number of items in a given key
     *
     * @param  int|string|null  key
     * @return int
     */
    public function count(key = null)
    {
        return count(this->get(key));
    }

    /**
     * Get an iterator for the stored items
     *
     * @return \ArrayIterator<TKey, TValue>
     */
    public function getIterator()
    {
        return new ArrayIterator(this->data);
    }

    /*
     * --------------------------------------------------------------
     * JsonSerializable interface
     * --------------------------------------------------------------
     */

    /**
     * Return items for JSON serialization
     *
     * @return array<TKey, TValue>
     */
    public function jsonSerialize()
    {
        return this->data;
    }
}