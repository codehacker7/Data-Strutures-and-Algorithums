public class moveDuplicatesOptimized {
    public static void main(String[] args) {
        int[] arr = { 1, 1, 1, 2, 2, 3, 4, 5 };

        int[] newarr = new int[arr.length];

        int counter = arr.length - 1;
        int frontcounter = 0;

        int i = 0;
        int j = 1;
        int count = 0;
        while (j < arr.length) {
            if (arr[i] == arr[j]) {
                count++;
            } else {
                if (count != 0) {
                    int storei = i;
                    for (int k = 0; k <= count; k++) {
                        newarr[counter] = arr[storei++];
                        counter--;
                    }
                } else if (count == 0) {
                    newarr[frontcounter] = arr[i];
                    frontcounter++;
                }
                i = i + count + 1;
                count = 0;
            }
            j++;

        }
        newarr[frontcounter] = arr[arr.length - 1];

        for (int k = 0; k < newarr.length; k++) {
            System.out.println(newarr[k]);
        }
    }
}
