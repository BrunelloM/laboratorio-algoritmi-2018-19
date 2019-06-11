package kruskalAlgorithmUsage;

/**
 * @author Brunello Matteo, Caresio Lorenzo
 */

public class Record {

  private String firstCity;
  private String secondCity;
  private double distance;

  public Record() {
    this.firstCity = null;
    this.secondCity = null;
    this.distance = 0.00;
  }

  public Record(String firstCity, String secondCity, double distance) {
    this.firstCity = firstCity;
    this.secondCity = secondCity;
    this.distance = distance;
  }

  public String getFirstCity() {
    return this.firstCity;
  }

  public String getSecondCity() {
    return this.secondCity;
  }

  public double getDistance() {
    return this.distance;
  }

  public void setFirstCity(String value) {
    this.firstCity = value;
  }

  public void setSecondCity(String value) {
    this.secondCity = value;
  }

  public void setDistance(double value) {
    this.distance = value;
  }

}
