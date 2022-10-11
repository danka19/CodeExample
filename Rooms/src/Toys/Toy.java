package Toys;

/**
 * Основной класс игрушек, находится на вершине иерархии
 */
public class Toy {
    protected double cost;

    public Toy(){}

    public Toy(double cost){
        this.cost = cost;
    }

    public double getCost() {
        return cost;
    }

    public void setCost(double cost){
        this.cost = cost;
    }

    @Override
    public String toString() {
        return "Toy: " +
                "cost " + cost;
    }
}
