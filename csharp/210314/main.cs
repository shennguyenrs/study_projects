using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

[Serializable]
public class Movie {
    public string Name { get; set; }
    public int Length { get; set; }
    public string Year { get; set; }

    public Movie() { }
    public Movie(string name, int length, string year) {
        this.Name = name;
        this.Length = length;
        this.Year = year;
    }
}

public class Program
{
    public void AddMovie(List<Movie> database)
    {
        Console.Write("Name:");
        string name = Console.ReadLine();
        Console.Write("Length (min):");
        int length = Convert.ToInt32(Console.ReadLine());
        Console.Write("Year:");
        string year = Console.ReadLine();

        database.Add(new Movie(name, length, year));
    }

    public void ShowMovies(List<Movie> database)
    {
        int totalTime = 0;
        for (int i=0; i<database.Count; i+=1)
        {
            if(i==0) Console.Write("\r");
            Console.WriteLine(database[i].Name + " (" + database[i].Year + "), " + database[i].Length + " minutes.  ");
            totalTime += database[i].Length;
        }
        if(database.Count==0) Console.Write("\r");
		Console.WriteLine();
        Console.WriteLine("\rTotal of "+database.Count+" movies and "+totalTime+" minutes.");
    }

    public void DeleteMovies(List<Movie> database)
    {
        for (int i=0; i<database.Count; i+=1)
        {
            Console.WriteLine((i+1) +") "+ database[i].Name + " (" + database[i].Year + "), " + database[i].Length + " minutes.  ");
        }
        Console.Write("Input: ");
        int index = Convert.ToInt32(Console.ReadLine());
        database.RemoveAt(index-1);
    }

    public void SaveData(List<Movie> database)
    {
        string filename = "database.xml";
        XmlSerializer serializer = new XmlSerializer(typeof(List<Movie>));
        using (StreamWriter sw = new StreamWriter(filename))
        {
            serializer.Serialize(sw, database);
            sw.Close();
        }
        Console.WriteLine("\rDatabase saved.");
    }

    public List<Movie> LoadData()
    {   
        string filename = "database.xml";
        List<Movie> database = new List<Movie> {};
        if(File.Exists(filename)) 
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Movie>));
            using(FileStream stream = File.OpenRead(filename))
            {
                database= (List<Movie>)serializer.Deserialize(stream);
            }
            Console.WriteLine("\rDatabase loaded.");
        } else {
            Console.WriteLine("No database available.");
        }
        return database;
    }
}

class MainClass
{
    static void Main()
    {
        List<Movie> database = new List<Movie>() {};
        Program app = new Program();

        while(true) {
			Console.WriteLine("\n\r");
            Console.WriteLine("\rMovie Watchlog");
            Console.WriteLine("==============");
            Console.WriteLine("1) Add a Movie");
            Console.WriteLine("2) Delete a Movie");
            Console.WriteLine("3) Show Report");
            Console.WriteLine("4) Load Database");
            Console.WriteLine("5) Save Database");
            Console.WriteLine("6) Quit");
            Console.Write("Input: ");

            string choose = Console.ReadLine();
            Console.WriteLine();

            if(choose=="6") {
				Console.Write("\r");
				break;
			}

            switch(choose){
                case "1":
                    Console.WriteLine("\rAdd a Movie:");
                    app.AddMovie(database);
                    continue;
                case "2":
                    Console.WriteLine("\rDelete a Movie:");
                    app.DeleteMovies(database);
                    continue;
                case "3":
                    app.ShowMovies(database);
                    continue;
                case "4":
                    database = app.LoadData();
                    continue;
                case "5":
                    app.SaveData(database);
                    continue;
                default:
                    Console.WriteLine("\rUnknown command");
                    continue;
            }
        }
    }
}