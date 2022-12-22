//Main purpose of this class is converting an array of bytes into individual 4x4 matrices that can be encrypted with the algorithm.
public class ByteFile {
    private final byte[] bytes;
    public ByteFile(byte[] input)
    {
        bytes = input;
    }

    public int BlockCount()
    {
        return Math.ceilDiv(bytes.length,16);
    }

    public byte[][] Block(int index) {
        byte[] input = new byte[16];
        if((index*16)+16 < bytes.length)
        {
            System.arraycopy(bytes, index * 16, input, 0, 16);
        }
        else   //Handling edge case where length of text isn't divisible by 16.
        {
            for(int i = 0; i < 16; i++)
            {
                if((index * 16)+i < bytes.length)
                {
                    input[i] = bytes[(index * 16)+i];
                }else
                {
                    input[i] = 0;
                }
            }
        }

        byte[][] result = new byte[4][4];
        for(int i = 0; i < 16; i++)
        {
            result[i/4][i%4] = input[i];
        }
        return result;
    }
}
