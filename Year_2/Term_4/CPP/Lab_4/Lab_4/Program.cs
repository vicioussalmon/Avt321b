using System;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Xml.Linq;

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
        public override string ToString() { 
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
        public override string ToString() {
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
        public override string ToString() { 
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
    class Container {
        private Product[] products;
        private int count;

        public Container()
        {
            count = 0;
            products = new Product[count];
        }

        public void AddProduct(Product product)
        {
            Product[] temp = new Product[count + 1];
            for (int i = 0; i < count; i++)
            {
                temp[i] = products[i];
            }
            temp[count] = product;
            products = temp;
            count++;
        }

        public void DeleteProduct(int index)
        {
            if (index < 0 || index >= count)
            {
                Console.WriteLine("Invalid index.");
            }
            else
            {
                Product[] temp = new Product[count - 1];
                for (int i = 0; i < index; i++)
                {
                    temp[i] = products[i];
                }
                for (int i = index; i < count - 1; i++)
                {
                    temp[i] = products[i + 1];
                }
                products = temp;
                count--;
            }
        }

        public void SortProductsByName()
        {
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (products[i].Name.CompareTo(products[j].Name) > 0)
                    {
                        Product temp = products[i];
                        products[i] = products[j];
                        products[j] = temp;
                    }
                }
            }
        }

        

        public void PrintProducts()
        {
            Console.WriteLine("Choosed Products):");
            Console.WriteLine("-------------------");
            short i = 0;
            foreach (Product p in products)
            {
                Console.WriteLine(" ----- Item " + i + "---- ");
                Console.WriteLine(p.ToString());
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
                Console.WriteLine("\n"+book+"\n");
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
            int select = int.Parse(Console.ReadLine());
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
            char choice = char.Parse(Console.ReadLine());
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
            if (int.TryParse(Console.ReadLine(), out productToDelete))
            {
                ChoosedProdukts.DeleteProduct(productToDelete);
            }
            else
                Console.WriteLine("Oops.. Fail! Unknown index!(・・ )?");
        }
    }


}