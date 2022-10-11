package vegetables;

/**
 * Сопоставление овощей по их весу в салате
 */
public class WeightComparator implements java.util.Comparator<Vegetable>{
	public int compare(Vegetable v1, Vegetable v2) {
        return (int) (v1.getWeight() - v2.getWeight());
    }
}