package Rooms;

import Toys.Car;
import Toys.*;
import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

public class PlayRoomTest {

    @Test
    public void sort() {

        ArrayList<Toy> toys = new ArrayList<>();
        Toy cube = new Cube(100, "green");
        Toy ball = new Ball(25, "basketball");

        toys.add(cube);
        toys.add(ball);

        Toy[] actual = new Toy[2];
        actual[0] = ball;
        actual[1] = cube;

        Toy[] expected = PlayRoom.sort(toys);

        Assert.assertArrayEquals(expected, actual);

    }
}
