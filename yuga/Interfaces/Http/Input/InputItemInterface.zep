/**
 * @author Mahad Tech Solutions
 */
namespace Yuga\Interfaces\Http\Input;

interface InputItemInterface
{

    public function getIndex();

    public function setIndex(index);

    public function getName();

    public function setName(name);

    public function getValue();

    public function __toString();

}