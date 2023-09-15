namespace Yuga\Carbon;

use Closure;
use DateTime;
use DatePeriod;
use DateTimeZone;
use JsonSerializable;
use DateTimeInterface;
use InvalidArgumentException;

class Carbon extends DateTime implements JsonSerializable
{
    const DEFAULT_TO_STRING_FORMAT = "Y-m-d H:i:s";
    protected static toStringFormat = self::DEFAULT_TO_STRING_FORMAT;

    public function __construct(time = null, tz = null)
    {
        var timezone;
        let timezone = static::safeCreateDateTimeZone(tz);
        parent::__construct((time == null) ? "now" : time, timezone);
    }

    public function __toString()
    {
        return this->format(self::toStringFormat);
    }

    public function jsonSerialize()
    {
        var carbon = this;

        return call_user_func(function () use (carbon) {
            return get_object_vars(carbon);
        });
    }

    /**
     * Format the instance as date
     *
     * @return string
     */
    public function toDateString()
    {
        return this->format("Y-m-d");
    }

    /**
     * Format the instance as a readable date
     *
     * @return string
     */
    public function toFormattedDateString()
    {
        return this->format("M j, Y");
    }

    /**
     * Format the instance as time
     *
     * @return string
     */
    public function toTimeString()
    {
        return this->format("H:i:s");
    }

    /**
     * Format the instance as date and time
     *
     * @return string
     */
    public function toDateTimeString()
    {
        return this->format("Y-m-d H:i:s");
    }

    /**
     * Format the instance with day, date and time
     *
     * @return string
     */
    public function toDayDateTimeString()
    {
        return this->format("D, M j, Y g:i A");
    }

    protected static function safeCreateDateTimeZone(objectVal)
    {
        if (objectVal === null) {
            // Don"t return null... avoid Bug #52063 in PHP <5.3.6
            return new DateTimeZone(date_default_timezone_get());
        }

        if (objectVal instanceof DateTimeZone) {
            return objectVal;
        }

        if (is_numeric(objectVal)) {
            var tzName = timezone_name_from_abbr(null, objectVal * 3600, true);

            if (tzName === false) {
                throw new InvalidArgumentException("Unknown or bad timezone (".objectVal.")");
            }

            let objectVal = tzName;
        }

        var tz = timezone_open((string) objectVal);

        if (tz === false) {
            throw new InvalidArgumentException("Unknown or bad timezone (".objectVal.")");
        }

        return tz;
    }
    
    /**
     * Get a Carbon instance for the current date and time.
     *
     * @param \DateTimeZone|string|null tz
     *
     * @return static
     */
    public static function now(tz = null)
    {
        return new self(null, tz);
    }

}