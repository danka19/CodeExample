package vegetables;

/**
 * Помидор
 */
public class Tomato extends NightshadeVegetable {

	/**
	 * Конструктор по умолчанию
	 */
	public Tomato() {
		super("Помидор", 18);
	}
	
	/**
	 * Constructor with parameters. Creates a Tomato of a given weight.
	 * @param weight the mass of the vegetable that will be created
	 */
	public Tomato(double weight) {
		super("Помидор", 18, weight);
	}
}
