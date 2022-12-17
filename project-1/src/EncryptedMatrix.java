
public class EncryptedMatrix implements CipherMatrix{
    private final byte[][] bytes;
    public EncryptedMatrix(byte[][] input)
    {
        bytes = input;
    }
    private byte[] Column(int index)
    {
        byte[] result = new byte[4];
        for(int i = 0; i < 4; i++)
            result[i] = bytes[i][index];
        return result;
    }

    public byte[] ByteArray() {
        byte[] result = new byte[16];
        for(int i = 0; i < 16; i++)
        {
            result[i] = bytes[i/4][i%4];
        }
        return result;
    }

    public EncryptedMatrix Substituted()
    {
        byte[][] result = new byte[4][4];
        for(int i = 0; i < 4; i++)
        {
            for(int y = 0; y < 4; y++)
            {
                result[i][y] = new EncodedByte(bytes[i][y]).SBoxValue();
            }
        }
        return new EncryptedMatrix(result);
    }
    public EncryptedMatrix MixedColumns()
    {
        byte[][] result = new byte[4][4];
        for(int i = 0; i < 4; i++)
        {
            byte[] column = this.Column(i);
            EncodedByte[] EncBytes = new EncodedByte[4];
            for (int y = 0; y < 4; y++)
            {
                EncBytes[y] = new EncodedByte(column[y]);
            }
            result[0][i] = (byte) (EncBytes[0].MultipliedBy2() ^ EncBytes[1].MultipliedBy3() ^ column[2] ^ column[3]);
            result[1][i] = (byte) (column[0] ^ EncBytes[1].MultipliedBy2() ^ EncBytes[2].MultipliedBy3() ^ column[3]);
            result[2][i] = (byte) (column[0] ^ column[1] ^ EncBytes[2].MultipliedBy2() ^ EncBytes[3].MultipliedBy3());
            result[3][i] = (byte) (EncBytes[0].MultipliedBy3() ^ column[1] ^ column[2] ^ EncBytes[3].MultipliedBy2());
        }
        return new EncryptedMatrix(result);
    }
    public EncryptedMatrix Shifted()
    {
        byte[][] newMatrix = new byte[4][4];
        for(int i = 0; i < 4; i++)
        {
            newMatrix[i] = new Row(this.bytes[i]).ShiftedLeft(i);
        }
        return new EncryptedMatrix(newMatrix);
    }
    public EncryptedMatrix AddedRoundKey(KeyMatrix keyMatrix)
    {
        byte[][] result = new byte[4][4];
        byte[][] key = keyMatrix.Key();
        for(int i = 0; i < 4; i++)
        {
            for(int y = 0; y < 4; y++)
            {
                result[i][y] = (byte) (bytes[i][y] ^ key[i][y]);
            }
        }
        return new EncryptedMatrix(result);
    }
}
