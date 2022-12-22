public class RCon {
    private final byte value;
    public RCon(byte input)
    {
        value = input;
    }
    public RCon Next()
    {
        int newValue = value*2;
        if(newValue >= 0x80)
        {
            newValue ^= 0x1B;
        }
        return new RCon((byte) newValue);
    }
    public byte Value()
    {
        return value;
    }
}
