using System;
using System.IO;
using System.IO.Pipes;
public struct Data
{
    public int num1;
    public int num2;
}
class Client
{
    static void Main()
    {
        using NamedPipeClientStream pipeClient = new NamedPipeClientStream(".", "channel", PipeDirection.InOut);
        pipeClient.Connect();
        Console.WriteLine("Клиент подключился к пивному бочонку");
            new NamedPipeClientStream(".", "testpipe", PipeDirection.In)
        {

            // Connect to the pipe or wait until the pipe is available.
            Console.Write("Attempting to connect to pipe...");
            pipeClient.Connect();

            Console.WriteLine("Connected to pipe.");
            Console.WriteLine("There are currently {0} pipe server instances open.",
               pipeClient.NumberOfServerInstances);
            using (StreamReader sr = new StreamReader(pipeClient))
            {
                // Display the read text to the console
                string temp;
                while ((temp = sr.ReadLine()) != null)
                {
                    Console.WriteLine("Received from server: {0}", temp);
                }
            }
        }
        Console.Write("Press Enter to continue...");
        Console.ReadLine();
    }
}
