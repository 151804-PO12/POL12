public interface Forecast {
    int Temperature(String Location);
    final class Fake implements Forecast
    {
        @Override
        public int Temperature(String Location)
        {
            return 24;
        }
    }
}
