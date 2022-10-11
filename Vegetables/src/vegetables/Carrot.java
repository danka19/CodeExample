package vegetables;

/**
 * Морковь
 */
public class Carrot extends RootVegetable{
	
	/**
	 * Конструктор по умолчанию
	 */
	public Carrot() {
		super("Carrot", 41);
	}
	
	/**
	 * Конструктор с входным папаметром веса
	 */
	public Carrot(double weight) {
		super("Carrot", 41, weight);
	}
}