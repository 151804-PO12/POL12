public class Weather{
    private Forecast forecast;
    public Weather(Forecast input)
    {
        forecast = input;
    }
    public int Temperature(String Location)
    {
        return forecast.Temperature(Location);
    }
}
