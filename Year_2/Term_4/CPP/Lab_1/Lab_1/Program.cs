Console.WriteLine("Input your line");
string phrase = Convert.ToString(Console.ReadLine());
string[] words = phrase.Split(' ');
for (int i = 0; i < words.Length; i++)
{
    if (words[i].Length <= 3)
    {
        words[i] = "";
    }
}
for (int i = 0; i < words.Length; i++)
{

    Console.Write(words[i] + " ");
}