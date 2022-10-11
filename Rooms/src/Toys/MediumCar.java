package Toys;

/**
 * Средняя машина. Может быть на радиоуправлении.
 */
public class MediumCar extends Car{

    private boolean rc; //маишна на радиоуправлении?

    public MediumCar(double cost, String color, boolean rc) {
        super(cost, color);
        this.rc = rc;
    }

    public void setRc(boolean rc) {
        this.rc = rc;
    }

    public boolean getRc(){
        return rc;
    }

    @Override
    public String toString() {
        return "MediumCar: " +
                "cost " + getCost() +
                ", color " + color +
                ", rc " + rc ;
    }
}
