package kruskalAlgorithmUsage;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


/**
 * @author Brunello Matteo, Caresio Lorenzo
 */

 public class CsvFileReader {
   String csvFilePath;

   public CsvFileReader(String csvFilePath) {
     this.csvFilePath = csvFilePath;
   }

   public ArrayList<Record> getFileAsArrayList() {
     int rowCounts = 0;
     System.out.println("Loading file into the memory. (This process may take a long time)");
     ArrayList<Record> fileContent = new ArrayList<Record>();

     try {
       FileReader fr = new FileReader(this.csvFilePath);
       BufferedReader br = new BufferedReader(fr);
       String currentFileLine;

       while ((currentFileLine = br.readLine()) != null) {
         String[] lineContents = currentFileLine.split(","); // In CSV values are separated by commas

         Record currentRecord = new Record();
         currentRecord.setFirstCity(lineContents[0]);
         currentRecord.setFirstCity(lineContents[1]);
         currentRecord.setDistance(Double.parseDouble(lineContents[2]));
         fileContent.add(currentRecord);
         rowCounts++;
       }

     } catch (FileNotFoundException e) {
       System.err.println("The dataset file doesn't exists: Please provide a valid dataset filepath");
       e.printStackTrace();
     } catch (IOException e) {
       System.err.println("An error has occurred while trying to parse the dataset");
       e.printStackTrace();
     }
     System.out.println(rowCounts + " rows has been loaded into the memory.");
     return fileContent;
   }


 }
