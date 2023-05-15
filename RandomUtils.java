import java.util.Random;

public class RandomUtils {
    public static int[] randArray(int length, int min, int max) {
        Random rng = new Random();
        int[] output = new int[length];

        for (int i = 0; i < length; i++) {
            output[i] = rng.nextInt(min, max);
        }

        return output;
    }

    public static double[] randArray(int length, double min, double max) {
        Random rng = new Random();
        var output = new double[length];

        for (int i = 0; i < length; i++) {
            output[i] = rng.nextDouble(min, max);
        }

        return output;
    }

    public static int[] randArray(int length) {
        Random rng = new Random();
        int[] output = new int[length];
        for (int i = 0; i < length; i++) {
            output[i] = rng.nextInt();
        }

        return output;
    }
}
