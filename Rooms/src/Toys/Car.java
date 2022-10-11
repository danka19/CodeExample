package Toys;

/**
 * Фабричный паттерн для автомобилей различных размеров
 */
public abstract class Car extends Toy{

    protected String color;

    public Car(double cost, String color) {
        super(cost);
        this.color = color;
    }
}
