package vegetables;

/**
 * Класс расширяет интерфейс, чтобы сопоставлять овощи по колориям на 100г
 */
public class CaloriesComparator implements java.util.Comparator<Vegetable>{
	
	public int compare(Vegetable v1, Vegetable v2) {
        return (int) (v1.getCalories() - v2.getCalories());
    }
}