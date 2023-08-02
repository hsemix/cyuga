namespace Yuga;

class BooleanType
{

    public static function parse(str, defaultValue = false)
    {
        var boolValue = filter_var(str, FILTER_VALIDATE_BOOLEAN, FILTER_NULL_ON_FAILURE);

        if boolValue != null {
            return boolValue;
        }

        return defaultValue;
    }

}