using System;
using System.IO.Pipes;
using System.Runtime.CompilerServices;

public struct Pivo
{
    public int litr1;
    public int litr2;
}

class PivoClient
{
    static void Main()
    {
        using NamedPipeClientStream pivoClient = new NamedPipeClientStream(".", "channel", PipeDirection.InOut);
        pivoClient.Connect();
        Console.WriteLine("Клиент подключился к серверу");
        byte[] bytes = new byte[Unsafe.SizeOf<Pivo>()];
        pivoClient.Read(bytes, 0, bytes.Length);
        Pivo received_pivo = Unsafe.As<byte, Pivo>(ref bytes[0]);
        Console.WriteLine("Объём 1: " + received_pivo.litr1 + "литра");
        Console.WriteLine("Объём 2: " + received_pivo.litr2 + "литра");
        byte[] modified_bytes = new byte[Unsafe.SizeOf<Pivo>()];
        Unsafe.As<byte, Pivo>(ref modified_bytes[0]) = received_pivo;
        pivoClient.Write(modified_bytes, 0, modified_bytes.Length);
        Console.ReadKey();
    }
}