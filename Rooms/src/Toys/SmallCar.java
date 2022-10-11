package Toys;

/**
 * Игрушка - маленькая машина
 */
public class SmallCar extends Car{

    private boolean collectionModel; // это коллекционная модель?

    public SmallCar(double cost, String color, boolean collectionModel) {
        super(cost, color);
        this.collectionModel = collectionModel;
    }

    @Override
    public String toString() {
        return "SmallCar: " +
                "cost " + cost +
                ", color '" + color + '\'' +
                ", collectionModel " + collectionModel;
    }
}
