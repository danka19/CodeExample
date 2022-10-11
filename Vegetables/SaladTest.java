package vegetables;

import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class SaladTest {

    @Test
    public void countCalories() {

        List<Vegetable> ingredients = new ArrayList<Vegetable>();
        Vegetable carrot = new Carrot(120);
        Vegetable potato = new Potato(50);

        ingredients.add(carrot);
        ingredients.add(potato);

        double expected = carrot.getWeight()/100 * carrot.getCalories() + potato.getWeight()/100 * potato.getCalories();
        double actual = Salad.countCalories(ingredients);

        Assert.assertEquals(expected, actual, 2);
    }
} 