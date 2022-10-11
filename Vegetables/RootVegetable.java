package vegetables;

/**
 * Корневые овощи
 */
abstract public class RootVegetable extends Vegetable{		
	public RootVegetable(String name, double calories) {
		super(name, calories);
		setCategory("Корневые овощи");
	}
	
	public RootVegetable(String name, double calories, double weight) {
		super(name, calories, weight);
		setCategory("Корневые овощи");
	}
}