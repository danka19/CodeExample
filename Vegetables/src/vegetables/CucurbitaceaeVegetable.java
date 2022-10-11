package vegetables;

/**
 * тыквенные
 */
public class CucurbitaceaeVegetable extends Vegetable{

	public CucurbitaceaeVegetable(String name, double calories) {
		super(name, calories);
		setCategory("Тыквенные овощи");
	}
	
	public CucurbitaceaeVegetable(String name, double calories, double weight) {
		super(name, calories, weight);
		setCategory("Тыквенные овощи");
	}
}
