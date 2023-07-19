namespace Yuga\Support;

class Str
{
    /**
     * Determine if a given string contains a given substring.
     *
     * @param  string  haystack
     * @param  string|array  needles
     * @return bool
     */
    public static function contains(haystack, needles)
    {
        var needle;

        for needle in (array) needles {
        
            if (needle !== "" && mb_strpos(haystack, needle) !== false) {
                return true;
            }
        }

        return false;
    }

    /**
     * Determine if a given string starts with a given substring.
     *
     * @param  string  haystack
     * @param  string|array  needles
     * @return bool
     */
    public static function startsWith(haystack, needles)
    {
        var needle;
        
        for needle in (array) needles {
            if (needle != "" && substr(haystack, 0, strlen(needle)) == (string) needle) {
                return true;
            }
        }

        return false;
    }

    /**
	 * Ends the haystack string with the suffix needle?
	 */
	public static function endsWith(string haystack, string needle) -> bool
	{
		return strlen(needle) == 0 || substr(haystack, -strlen(needle)) == needle;
    }
}