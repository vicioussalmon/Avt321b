using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Net.Sockets;
using System.Security.Policy;

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
    //Class Book
    public class Book : Product
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
        public override string ToString()
        {
            return base.ToString() + "\nBook:" + BookName + "\nAuthor:" + AuthorName;
        }
    }
    public class SingleBook : Book
    {

        public SingleBook() : base() { }
        public SingleBook(string name, decimal price, string bookName, string authorName) : base(name, price, bookName, authorName) { }
        public override string ToString()
        {
            return base.ToString() + "\nQuantity of books: 1";
        }
    }
    public class BookSeries : Book
    {

        public BookSeries() : base() { }
        public BookSeries(string name, decimal price, string bookName, string authorName) : base(name, price, bookName, authorName) { }
        public override string ToString()
        {
            return base.ToString() + "\nThis is a serie of books";
        }
    }
    //Class Bookmarks set
    public class BookmarksSet : Product
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
    public class TranslucentBookmarks : BookmarksSet
    {
        TranslucentBookmarks() : base() { }
        public TranslucentBookmarks(string name, decimal price, string colour, float quantity) : base(name, price, colour, quantity) { }
        public override string ToString()
        {
            return base.ToString() + "\nThis set is translucent";
        }

    }
    public class OpaqueBookmarks : BookmarksSet
    {
        OpaqueBookmarks() : base() { }
        public OpaqueBookmarks(string name, decimal price, string colour, float quantity) : base(name, price, colour, quantity) { }
        public override string ToString()
        {
            return base.ToString() + "\nThis set is opaque";
        }

    }
    //Class Posters
    public class Posters : Product
    {
        public char Size { get; private set; }

        public Posters() : base()
        {
            Size = ' ';
        }

        public Posters(string name, decimal price, char size) : base(name, price)
        {
            Size = size;
        }

        public override string ToString()
        {

            return base.ToString() + "\nSize:" + Size;
        }
    }
    public class Coloured : Posters
    {
        public Coloured() : base() { }
        public Coloured(string name, decimal price, char size) : base(name, price, size) { }
        public override string ToString()
        {
            return base.ToString() + "\nColoured: Yes";
        }
    }
    public class UnColoured : Posters
    {
        public UnColoured() : base() { }
        public UnColoured(string name, decimal price, char size) : base(name, price, size) { }
        public override string ToString()
        {
            return base.ToString() + "\nColoured: No";
        }
    }
    //Class Container
    class Container
    {

    }
    class Program
    {
        Container ChoosedProdukts = new Container();
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("Welcome to the Book Store!");
                Console.WriteLine("Please, choose an operation!");
                Console.WriteLine("1 -- Buy Books");
                Console.WriteLine("2 -- Buy Set of Bookmarks");
                Console.WriteLine("3 -- Buy Posters");
                Console.WriteLine("4 -- View Choosed Products");
                Console.WriteLine("5 -- Delete a Choosed Product");
                Console.WriteLine("6 -- Sort by price from lover to higher");
                Console.WriteLine("0 -- Exit");

                int select = int.Parse(Console.ReadLine());

                switch (select)
                {
                    case 1:
                        BuyBook(ChoosedProdukts);
                        Console.WriteLine("\n\n");
                        break;
                    case 2:
                        BuyBookmarksSet(ChoosedProdukts);
                        Console.WriteLine("\n\n");
                        break;
                    case 3:
                        BuyPosters(ChoosedProdukts);
                        Console.WriteLine("\n\n");
                        break;
                    case 4:
                        Console.Write(ChoosedProdukts);
                        Console.WriteLine("\n\n");
                        break;
                    case 5:
                        RemoveChoosedProdukts(ChoosedProdukts);
                        Console.WriteLine("\n\n");
                        break;

                    case 6:
                        ChoosedProdukts.Sort();
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
        static void BuyBook(Container ChoosedProdukts)
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

            Console.WriteLine("Please, choose type of book!");
            Console.WriteLine("1 -- Single Book");
            Console.WriteLine("2 -- Book Series");
            int select = int.Parse(Console.ReadLine());
            if (select == 1)
            {
                SingleBook book = new SingleBook(genre, price, bookName, authorName);
                Console.WriteLine("\n" + book + "\n");
                ChoosedProdukts.Add(book);
            }
            else if (select == 2)
            {
                BookSeries book = new BookSeries(genre, price, bookName, authorName);
                Console.WriteLine("\n" + book + "\n");
                ChoosedProdukts.Add(book);
            }
            else Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
        }
        static void BuyBookmarksSet(Container ChoosedProdukts)
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

            Console.Write("Select type of bookmarks set!");
            Console.WriteLine("1 -- Translucent Bookmarks");
            Console.WriteLine("2 -- Opaque Bookmarks");
            int select = int.Parse(Console.ReadLine());
            if (select == 1)
            {
                TranslucentBookmarks bookmarks = new TranslucentBookmarks(name, price, colour, quantity);
                Console.WriteLine("\n" + bookmarks + "\n");
                ChoosedProdukts.Add(bookmarks);
            }
            else if (select == 2)
            {
                OpaqueBookmarks bookmarks = new OpaqueBookmarks(name, price, colour, quantity);
                Console.WriteLine("\n" + bookmarks + "\n");
                ChoosedProdukts.Add(bookmarks);
            }
            else Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
        }
        static void BuyPosters(Container ChoosedProdukts)
        {
            Console.WriteLine("You`re choosing posters.");
            Console.WriteLine("Please enter the name of poster`s fandom (f.e. Avengers):");
            string name = Console.ReadLine();

            Console.WriteLine("Please enter the price of the poster:");
            decimal price = decimal.Parse(Console.ReadLine());

            Console.WriteLine("Please enter the size of the corn bucket (S - A4 M - A3 L - A2 XL - A1 XXL - A0):");
            char size = char.Parse(Console.ReadLine());

            Console.Write("Should your poster be cloured? ( Y or N )");
            char choice = char.Parse(Console.ReadLine());
            if (choice == 'Y')
            {
                Coloured poster = new Coloured(name, price, size);
                Console.WriteLine("\n" + poster + "\n");
                ChoosedProdukts.Add(poster);
            }
            else if (choice == 'N')
            {
                UnColoured poster = new UnColoured(name, price, size);
                Console.WriteLine("\n" + poster + "\n");
                ChoosedProdukts.Add(poster);
            }
            else Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");

        }
        //static void ShowChoosedProducts()
        //{
        //    Console.WriteLine("Choosed Products):");
        //    Console.WriteLine("-------------------");
        //    short i = 1;
        //    foreach (Product product in ChoosedProdukts)
        //    {
        //        Console.WriteLine(" ----- Item " + i + "---- ");
        //        Console.WriteLine(product.ToString());
        //        Console.WriteLine();
        //        i++;
        //    }
        //    Console.WriteLine("-------------------");
        //}
        static void RemoveChoosedProdukts(Container ChoosedProdukts)
        {
            Console.WriteLine("Enter the index of removing produkt:");
            int index = int.Parse(Console.ReadLine());

            if (index > 0 && index <= ChoosedProdukts.Length())
            {
                Console.WriteLine("Removing");
                ChoosedProdukts.PrintByIndex(index - 1);
                ChoosedProdukts.Delete(index - 1);
            }
            else
                Console.WriteLine("Oops.. Fail! Unknown index!(・・ )?");
        }
    }


}