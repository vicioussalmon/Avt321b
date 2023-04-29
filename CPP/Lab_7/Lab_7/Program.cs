﻿using System;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Xml.Linq;

namespace BookStore
{
    //Lab_6
    class DataLogicException : Exception
    {
        public DataLogicException(string message) : base(message) { }
        public DataLogicException(string message, Exception innerException) : base(message, innerException) { }
    }
    //Lab_7
    interface IName : IComparable
    {
        string GetName();
        decimal GetPrice();
    }

    public class Product:IName
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

        string IName.GetName() { return Name; }
        decimal IName.GetPrice() { return Price; }

        public int CompareTo(object obj) { return Name.CompareTo(obj); }

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
            return base.ToString() + "\nThis book is one of the serie of books";
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
        private IName[] items;

        private int count;

        public Container()
        {
            items = new IName[0];
            count = 0;
        }

        public IName this[int i]
        {
            set { items[i] = value; }
            get
            {
                try
                {
                    return items[i];
                }
                catch (Exception ex)
                {
                    throw new DataLogicException("Out of range", ex);
                }
            }
        }

        public IName this[string name]
        {
            get
            {
                try
                {
                    foreach (IName p in items)
                        if (string.Equals(p.GetName(), name, StringComparison.OrdinalIgnoreCase))
                            return p;
                    return null;
                }

                catch (Exception ex)
                {
                    throw new DataLogicException("Out of range", ex);
                }


            }
        }

        public IName this[decimal price]
        {
            get
            {
                try
                {
                    foreach (IName p in items)
                        if (p.GetPrice() == price)
                            return p;
                    return null;
                }
                catch (Exception ex)
                {
                    throw new DataLogicException("Out of range", ex);
                }
            }
        }

        public void AddProduct(Product product)
        {
            IName[] temp = null;
            try
            {
                temp = new IName[count + 1];
                for (int i = 0; i < count; i++)
                {
                    temp[i] = items[i];
                }
                temp[count] = product;
                items = temp;
                count++;
            }
            catch (Exception ex)
            {
                throw new DataLogicException("Error adding an item to the container", ex);
            }
            finally
            {
                temp = null;
            }
        }

        public void DeleteProduct(int index)
        {
            IName[] temp = null;
            try
            {
                temp = new IName[count - 1];
                for (int i = 0; i < index; i++)
                {
                    temp[i] = items[i];
                }
                for (int i = index; i < count - 1; i++)
                {
                    temp[i] = items[i + 1];
                }
                items = temp;
                count--;
            }
            catch (Exception ex)
            {
                throw new DataLogicException("Error removing an item from the container", ex);
            }
            finally
            {
                temp = null;
            }
        }

        public void SortProductsByName()
        {
            Array.Sort(items, (p1, p2) => p1.GetName().CompareTo(p2.GetName()));
        }

        public void PrintProducts()
        {
            Console.WriteLine("Choosed Products):");
            Console.WriteLine("-------------------");
            short i = 0;
            foreach (Product p in items)
            {
                Console.WriteLine(" ----- Item " + i + "---- ");
                Console.WriteLine(p.ToString());
                i++;
            }
            Console.WriteLine("-------------------");
        }
        public int Length() { return count; }
    }
    class Program
    {

        static void Main(string[] args)
        {
            Container ChoosedProdukts = new Container();
            while (true)
            {
                Console.WriteLine("Welcome to the Book Store!");
                Console.WriteLine("Please, choose an operation!");
                Console.WriteLine("1 -- Buy Books");
                Console.WriteLine("2 -- Buy Set of Bookmarks");
                Console.WriteLine("3 -- Buy Posters");
                Console.WriteLine("4 -- View Choosed Products");
                Console.WriteLine("5 -- Delete a Choosed Product");
                Console.WriteLine("6 -- Sort produkts by name");
                Console.WriteLine("7 -- Search a product");
                Console.WriteLine("0 -- Exit");

            MCH: int select = -1;
                try
                {
                    select = int.Parse(Console.ReadLine());
                }
                catch (FormatException ex)
                {
                    Console.WriteLine("Uncorrect choice. Please try one more time. (・・ )?");
                    goto MCH;
                }

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
                        ChoosedProdukts.PrintProducts();
                        // Console.Write(ChoosedProdukts);
                        Console.WriteLine("\n\n");
                        break;
                    case 5:
                        RemoveChoosedProdukts(ChoosedProdukts);
                        Console.WriteLine("\n\n");
                        break;

                    case 6:
                        ChoosedProdukts.SortProductsByName();
                        break;
                    case 7:
                        SearchBy(ChoosedProdukts);
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
        BOOKTYPE: int select;
            try
            {
                select = int.Parse(Console.ReadLine());
            }
            catch (FormatException ex)
            {
                Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
                goto BOOKTYPE;
            }
            if (select == 1)
            {
                SingleBook book = new SingleBook(genre, price, bookName, authorName);
                Console.WriteLine("\n" + book + "\n");
                ChoosedProdukts.AddProduct(book);
            }
            else if (select == 2)
            {
                BookSeries book = new BookSeries(genre, price, bookName, authorName);
                Console.WriteLine("\n" + book + "\n");
                ChoosedProdukts.AddProduct(book);
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

            Console.WriteLine("Select type of bookmarks set!");
            Console.WriteLine("1 -- Translucent Bookmarks");
            Console.WriteLine("2 -- Opaque Bookmarks");
        BOOKMARKSTYPE: int select;
            try
            {
                select = int.Parse(Console.ReadLine());
            }
            catch (FormatException ex)
            {
                Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
                goto BOOKMARKSTYPE;
            }
            if (select == 1)
            {
                TranslucentBookmarks bookmarks = new TranslucentBookmarks(name, price, colour, quantity);
                Console.WriteLine("\n" + bookmarks + "\n");
                ChoosedProdukts.AddProduct(bookmarks);
            }
            else if (select == 2)
            {
                OpaqueBookmarks bookmarks = new OpaqueBookmarks(name, price, colour, quantity);
                Console.WriteLine("\n" + bookmarks + "\n");
                ChoosedProdukts.AddProduct(bookmarks);
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

            Console.WriteLine("Should your poster be cloured? ( Y or N )");
        POSTERSTYPE: char choice;
            try
            {
                choice = char.Parse(Console.ReadLine());
            }
            catch (FormatException ex)
            {
                Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
                goto POSTERSTYPE;
            }
            if (choice == 'Y')
            {
                Coloured poster = new Coloured(name, price, size);
                Console.WriteLine("\n" + poster + "\n");
                ChoosedProdukts.AddProduct(poster);
            }
            else if (choice == 'N')
            {
                UnColoured poster = new UnColoured(name, price, size);
                Console.WriteLine("\n" + poster + "\n");
                ChoosedProdukts.AddProduct(poster);
            }
            else Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");

        }
        static void RemoveChoosedProdukts(Container ChoosedProdukts)
        {
            Console.WriteLine("Enter the index of removing produkt:");
            int productToDelete;
            int.TryParse(Console.ReadLine(), out productToDelete);

            try
            {
                ChoosedProdukts.DeleteProduct(productToDelete);
            }
            catch (Exception ex) { Console.WriteLine(ex.ToString()); }

        }
        static void SearchBy(Container ChoosedProdukts)
        {
            Console.WriteLine("Please, choose type of searching!");
            Console.WriteLine("1 -- Search by index");
            Console.WriteLine("2 -- Search by price");
            Console.WriteLine("3 -- Search by name");
            Console.WriteLine("0 -- Back");
        DCH: int choice = -1;
            try
            {
                choice = int.Parse(Console.ReadLine());
            }
            catch (FormatException ex)
            {
                Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
                goto DCH;
            }
            switch (choice)
            {
                case 1:
                    Console.Write("Input your index -- ");
                    int index = int.Parse(Console.ReadLine());
                    Console.WriteLine("\n" + ChoosedProdukts[index - 1] + "\n");
                    break;

                case 2:
                    Console.Write("Input your price -- ");
                    decimal price = decimal.Parse(Console.ReadLine());
                    Console.WriteLine("\n" + ChoosedProdukts[price] + "\n");
                    break;

                case 3:
                    Console.Write("Input your name -- ");
                    string name = Console.ReadLine();
                    Console.WriteLine("\n" + ChoosedProdukts[name] + "\n");
                    break;

                case 0:
                    break;

                default:
                    Console.WriteLine("\n\t\tOops.. Fail! Unknown product!(・・ )?\n");
                    break;
            }

        }
    }


}