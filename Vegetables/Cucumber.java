package vegetables;

public class Cucumber extends CucurbitaceaeVegetable{

	/**
	 * Конструктор по умолчанию
	 */
	public Cucumber() {
		super("Морковь", 16);
	}
	
	/**
	 * Конструктор с входным параметром веса
	 */
	public Cucumber(double weight) {
		super("Морковь", 16, weight);
	}
}
