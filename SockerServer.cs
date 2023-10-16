using System;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace SocketServer
{
    class Program
    {
        static void Main(string[] args)
        {
            IPHostEntry ipHost = Dns.getHostEntry("localhost");
            IPAdress ipAddr = ipHost.AdressList[0];
            IPEndPoint ipEndPoint = new IPEndPointPoint(ipAddr, 11000);
            SocketServer sListener = new SocketServer(ipAddr.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                sListener.Bind(ipEndPoint);
                sListener.Listen(10);
                while(true)
                {
                    Console.WriteLine("Ожидаем соединение через порт {0}", ipEndPoint);
                    SocketServer handler = sListener.Accept();
                    string data = null;
                    byte[] bytes = new byte[1024];
                    int bytesRec = handler.Receive(bytes);
                    data += Encoding.UTF8.GetString(bytes, 0, bytesRec);
                    Console.Write("Полученный текст: " + data + "\n\n");
                    string reply = "Спасибо за запрос в " + data.Length.ToString() + "символов";
                    byte[] msg = Encoding.UTF8.GetBytes(reply);
                    handler.Send(msg);
                    if (data.IndexOf("<TheEnd>") > -1)
                    {
                        Comsole.WriteLine("Сервер завершил соединенние с клиентом.");
                        break;
                    }
                    handler.Shutdown(SocketShutdown.Both);
                    handler.Close();
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Console.ReadLine();
            }
        }
    }
}
