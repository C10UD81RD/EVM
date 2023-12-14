using System.Runtime.CompilerServices;
using System.IO.Pipes;

public struct Pivo
{
    public int litr1;
    public int litr2;
}
class PivoServer
{
    static void Main()
    {
        using NamedPipeServerStream pivoServer = new("channel", PipeDirection.InOut);
        Console.WriteLine("Ожидается подключения клиента к серверу");
        pivoServer.WaitForConnection();
        Console.WriteLine("Клиент подключен");
        StreamWriter sw = new(pivoServer) {
            AutoFlush = true
        };

        Console.Write("Введите первый объём пива: ");
        int litr_1 = int.Parse(Console.ReadLine());
        Console.Write("Введите второй объём пива: ");
        int litr_2 = int.Parse(Console.ReadLine());
        Pivo msg = new() {
            litr1 = litr_1,
            litr2 = litr_2
        };

        byte[] bytes = new byte[Unsafe.SizeOf<Pivo>()];
        Unsafe.As<byte, Pivo>(ref bytes[0]) = msg;
        sw.BaseStream.Write(bytes, 0, bytes.Length);
        byte[] received_bytes = new byte[Unsafe.SizeOf<Pivo>()];
        sw.BaseStream.Read(received_bytes, 0, received_bytes.Length);
        Pivo received_pivo = Unsafe.As<byte, Pivo>(ref received_bytes[0]);
        Console.WriteLine($"Полученные данные: первый объём = {received_pivo.litr1}, второй объём = {received_pivo.litr2}");
        Console.ReadKey();
    }
}

