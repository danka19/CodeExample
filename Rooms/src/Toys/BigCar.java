package Toys;

/**
 * Игрушка - большая машина
 */
public class BigCar extends Car{

    private boolean tipper; //это самосвал?

    public BigCar(double cost, String color, boolean tipper) {
        super(cost, color);
        this.tipper = tipper;
    }

    public void setTipper(boolean tipper) {
        this.tipper = tipper;
    }

    public boolean getTipper(){
        return tipper;
    }

    @Override
    public String toString() {
        return "BigCar: " +
                "cost " + cost +
                ", color " + color +
                ", tipper " + tipper;
    }
}
