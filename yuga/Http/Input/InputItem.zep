namespace Yuga\Http\Input;

use Yuga\Support\Str;
use Yuga\Interfaces\Http\Input\InputItemInterface;

class InputItem implements InputItemInterface
{
    public index;
    public name;
    public value;

    public function __construct(index, value = null)
    {
        let this->index = index;
        let this->value = value;

        // Make the name human friendly, by replace _ with space
        let this->name = this->index;

        if (Str::contains(this->name, "_")) {
            let this->name = str_replace("_", " ", this->name);
        }
        let this->name = ucfirst(this->name);
    }

    /**
     * @return string
     */
    public function getIndex()
    {
        return this->index;
    }

    public function setIndex(index)
    {
        let this->index = index;

        return this;
    }

    /**
     * @return string
     */
    public function getName()
    {
        return this->name;
    }

    /**
     * Set input name
     * @param string name
     * @return static this
     */
    public function setName(name)
    {
        let this->name = name;

        return this;
    }

    /**
     * @return string
     */
    public function getValue()
    {
        return this->value;
    }

    /**
     * Set input value
     * @param string value
     * @return static this
     */
    public function setValue(value)
    {
        let this->value = value;

        return this;
    }

    public function __toString()
    {
        return (string)this->value;
    }

}