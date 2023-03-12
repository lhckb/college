package estudos;

public class ConversaoPrimitivos {
    public static void main(String[] args) {
        int nine = 9;
        int five = 50000000;
        byte converted = (byte)five;
        System.out.println(converted);
        double res = (double)nine / (byte)five;
        System.out.println(res);
        short s1 = (short) -3L;
        System.out.println(s1);
        // boolean expression = 1;  --not allowed
        long high = 993298298322932L;
        int low = (int) high;
        float f1 = high;
        System.out.println(high);
        System.out.println(f1);

        double d1 = -11.1212121212121212121212121;
        int i1 = (int)d1;
        System.out.println(i1);

        float f2 = (float)d1;
        System.out.println(f2);

        int a2 = (int)222.00;
        short s2 = (short)a2;
        System.out.println(s2);

        Pessoa.nome = "luís";  // static attribute
        System.out.println(Pessoa.getNome());

        int[] arr = new int[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = i * 10;
        }
        for(int el : arr) {
            System.out.println(el);
        }
    }
}
