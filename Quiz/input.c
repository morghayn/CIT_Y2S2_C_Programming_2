
/* ~ C-ify this function
private static int inputNumber(int smallerThan, int largerThan, String message)
{
    int num;

    do
    {
        System.out.print(message);

        while (!sc.hasNextInt())
        {
            System.out.print(message);
            sc.next();
        }

        num = sc.nextInt();
    } while (num < smallerThan || num > largerThan);

    sc.nextLine();

    return num;
}
*/