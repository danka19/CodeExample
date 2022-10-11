package vegetables;

/**
 * Картошка
 */
public class Potato extends NightshadeVegetable{
	
	/**
	 * Конструктор по умолчанию
	 */
	public Potato() {
		super("Картошка", 77);
	}
	
	/**
	 * Конструктор с входящим параметром веса
	 */
	public Potato(double weight) {
		super("Картошка", 77, weight);
	}
}
