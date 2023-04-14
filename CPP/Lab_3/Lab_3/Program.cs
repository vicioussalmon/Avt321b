using System;
using System.Collections.Generic;
using System.Drawing;
using System.Net.Sockets;

namespace BookStore
{
    public class Product
    {
        public string Name { get; protected set; }
        public decimal Price { get; protected set; }
        public Product()
        {
            Name = "Unknown";
            Price = -1;
        }

        public Product(string names, decimal prices)
        {
            Name = names;
            Price = prices;
        }

        public override string ToString()
        {
            return "Name:" + Name + "\n" + "Price:" + Price;
        }
    }

    public class Book: Product
    {
        public string BookName { get; private set; }
        public string AuthorName { get; private set; }

        public Book() : base()
        {
            BookName = "Unknown";
            AuthorName = "Unknown";
        }

        public Book(string name, decimal price, string bookName, string authorName) : base(name, price)
        {
            BookName = bookName;
            AuthorName = authorName;
        }
        public override string ToString() {
            return base.ToString() + "\nBook:" + BookName + "\nAuthor:" + AuthorName;
        }
    }

    public class BookmarksSet :Product
    {
        public string Colour { get; private set; }
        public float QuantityInSet { get; private set; }

        public BookmarksSet() : base()
        {
            Colour = "Unknown";
            QuantityInSet = 0;
        }

        public BookmarksSet(string name, decimal price, string colour, float quantity) : base(name, price)
        {
            Colour = colour;
            QuantityInSet = quantity;
        }

        public override string ToString()
        {
            return base.ToString() + "\nColour:" + Colour + "\nQuantity:" + QuantityInSet;
        }
    }

    public class Posters : Product
    {

        public bool Coloured { get; private set; }
        public char Size { get; private set; }

        public Posters() : base()
        {
            Coloured = false;
            Size = ' ';
        }

        public Posters(string name, decimal price, bool coloured, char size) : base(name, price)
        {
            Coloured = coloured;
            Size = size;
        }

        public override string ToString()
        {
            string colouredString = Coloured ? "Yes" : "No";
            return base.ToString() + "\nColoured:" + colouredString + "\nSize:" + Size;
        }
    }

    class Program
    {
        static List<Product> choosedprodukts = new List<Product>();//added products
        static void Main(string[] args) {
            while (true) {
                Console.WriteLine("Welcome to the Book Store!");
                Console.WriteLine("Please, choose an operation!");
                Console.WriteLine("1 -- Buy Books");
                Console.WriteLine("2 -- Buy Set of Bookmarks");
                Console.WriteLine("3 -- Buy Posters");
                Console.WriteLine("4 -- View Choosed Products");
                Console.WriteLine("0 -- Exit");

                int select = int.Parse(Console.ReadLine());

                switch (select)
                {
                    case 1:
                        BuyBook();
                        Console.WriteLine("\n\n");
                        break;
                    case 2:
                        BuyBookmarksSet();
                        Console.WriteLine("\n\n");
                        break;
                    case 3:
                        BuyPosters();
                        Console.WriteLine("\n\n");
                        break;
                    case 4:
                        ShowChoosedProducts();
                        Console.WriteLine("\n\n");
                        break;
                    case 0:
                        Console.WriteLine("Thank you for shopping with us!");
                        return;
                    default:
                        Console.WriteLine("Uncorrect choice. Please try one more time. (・・ )?");
                        break;
                }
            }
            Console.WriteLine("Thank you for shopping with us!");
            Console.ReadLine();
        
        }
        static void BuyBook()
        {
            Console.WriteLine("You`re choosing a book.");
            Console.WriteLine("Please enter the kind of book and genre (f.e. Book.Detective or Manga.Fantasy or Comics.Adventures):");
            string genre = Console.ReadLine();

            Console.WriteLine("Please enter the price of the book:");
            decimal price = decimal.Parse(Console.ReadLine());

            Console.WriteLine("Please enter the name of the book:");
            string bookName = Console.ReadLine();

            Console.WriteLine("Please enter the name of the author:");
            string authorName = Console.ReadLine();

            Book book = new Book(genre, price, bookName, authorName);
            Console.WriteLine();
            Console.WriteLine(book.ToString());

            choosedprodukts.Add(book);
        }
        static void BuyBookmarksSet()
        {
            Console.WriteLine("You`re choosing a set of bookmarks.");
            Console.WriteLine("Please enter the name of the set (f.e. Spring):");
            string name = Console.ReadLine();

            Console.WriteLine("Please enter the price of the set:");
            decimal price = decimal.Parse(Console.ReadLine());

            Console.WriteLine("Please enter the colour of the set (f.e. Green):");
            string colour = Console.ReadLine();


            Console.WriteLine("Please enter the quantity of the bookmarks in set:");
            float quantity = float.Parse(Console.ReadLine());

            BookmarksSet bookmarksset = new BookmarksSet(name, price, colour, quantity);
            Console.WriteLine();
            Console.WriteLine(bookmarksset.ToString());

            choosedprodukts.Add(bookmarksset);
        }
        static void BuyPosters()
        {
            Console.WriteLine("You`re choosing posters.");
            Console.WriteLine("Please enter the name of poster`s fandom (f.e. Avengers):");
            string name = Console.ReadLine();

            Console.WriteLine("Please enter the price of the poster:");
            decimal price = decimal.Parse(Console.ReadLine());

            Console.WriteLine("Should the poster be coloured? (Y/N):");
            bool coloured = (Console.ReadLine().ToUpper() == "Y");

            Console.WriteLine("Please enter the size of the corn bucket (S - A4 M - A3 L - A2):");
            char size = char.Parse(Console.ReadLine());

            Posters posters = new Posters(name, price, coloured, size);
            Console.WriteLine();
            Console.WriteLine(posters.ToString());

            choosedprodukts.Add(posters);
        }
        static void ShowChoosedProducts()
        {
            Console.WriteLine("Choosed Products):");
            Console.WriteLine("-------------------");
            short i = 1;
            foreach (Product product in choosedprodukts)
            {
                Console.WriteLine(" ----- Item " + i + "---- ");
                Console.WriteLine(product.ToString());
                Console.WriteLine();
                i++;
            }
            Console.WriteLine("-------------------");
        }

    }
   

}