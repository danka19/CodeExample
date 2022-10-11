package vegetables;

/**
 * Паслён
 */
public class NightshadeVegetable extends Vegetable{
	
	public NightshadeVegetable(String name, double calories) {
		super(name, calories);
		setCategory("Паслёновые овощи");
	}
	
	public NightshadeVegetable(String name, double calories, double weight) {
		super(name, calories, weight);
		setCategory("Паслёновые овощи");
	}
}