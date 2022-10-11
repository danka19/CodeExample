package vegetables;

/**
 * Острые овощи
 */
public class SpicyVegetable extends Vegetable{
	
	public SpicyVegetable(String name, double calories) {
		super(name, calories);
		setCategory("Острые овощи");
	}
	
	public SpicyVegetable(String name, double calories, double weight) {
		super(name, calories, weight);
		setCategory("Острые овощи");
	}
}
