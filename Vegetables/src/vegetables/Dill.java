package vegetables;

/**
 * Укроп
 */
public class Dill extends SpicyVegetable{
	/**
	 * Конструктор по умолчанию
	 */
	public Dill() {
		super("Укроп", 43);
	}
	
	/**
	 * Конструктор с параметром веса
	 */
	public Dill(double weight) {
		super("Укроп", 43, weight);
	}
}
