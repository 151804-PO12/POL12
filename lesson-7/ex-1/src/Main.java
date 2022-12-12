public class Main {
    public static void main(String[] args)
    {
        Forecast fakeForecast = new Forecast.Fake();
        Weather currentWeather = new Weather(fakeForecast);
        System.out.println(currentWeather.Temperature("here"));
    }
}
