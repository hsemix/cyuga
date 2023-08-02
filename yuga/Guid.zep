namespace Yuga;

use Yuga\Support\Helpers;

class Guid
{

    public static function create(separator = false)
    {
        if (function_exists("com_create_guid")) {
            var guid = trim(com_create_guid(), "{}");

            if !separator {
                return str_replace("-", "", guid);
            }
            return guid;
        }

        var pattern = "%04X%04X-%04X-%04X-%04X-%04X%04X%04X"; 

        if (!separator) {
            let pattern = "%04X%04X%04X%04X%04X%04X%04X%04X";
        }

        return sprintf(pattern,
            mt_rand(0, 65535), mt_rand(0, 65535), mt_rand(0, 65535),
            mt_rand(16384, 20479), mt_rand(32768, 49151), mt_rand(0, 65535),
            mt_rand(0, 65535), mt_rand(0, 65535));
    }

    public static function encrypt(key, data, method = null)
    {
        if (method === null) {
            let method = Helpers::app()->getEncryptionMethod();
        }

        let key = substr(hash("sha256", key, true), 0, 16);
        var iv = openssl_random_pseudo_bytes(openssl_cipher_iv_length(method));
        let data = openssl_encrypt(data, method, key, 0, iv);

        return base64_encode(data . "|" . bin2hex(iv));
    }

    public static function decrypt(key, data, method = null)
    {
        if (method === null) {
            let method = Helpers::app()->getEncryptionMethod();
        }

        let key = substr(hash("sha256", key, true), 0, 16);

        var exploded = explode("|", base64_decode(data));

        let data = exploded[0];
        var iv = exploded[1];

        var binary = hex2bin(iv);
        if binary == false {
            return false;
        }

        let data = openssl_decrypt(data, method, key, 0, binary);

        return data;
    }

    /**
     * Creates an random password, with a given length.
     * @param int length
     * @return string
     * @throws \Exception
     */
    public static function createRandomPassword(length)
    {
        // var chars = "ABCDEFGHIJKLMNOPQRSTUVXYXW023456789";
        // mt_srand((double)microtime() * 1000000);
        // var i = 0;
        // var pass = "";
        // while i <= length {
        //     var num = mt_rand() % 33;
        //     var tmp = substr(chars, num, 1);
        //     let pass .= tmp;
        //     i++;
        // }

        // return pass;
    }

    /**
     * Creates random very unique string
     * @return string
     */
    public static function generateSalt()
    {
        return password_hash(uniqid(mt_rand(), true), PASSWORD_BCRYPT);
    }

}