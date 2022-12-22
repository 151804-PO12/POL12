public class DecryptedMatrix implements CipherMatrix{
    private final byte[][] bytes;
    public DecryptedMatrix(byte[][] input)
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
    public DecryptedMatrix Substituted()
    {
        byte[][] result = new byte[4][4];
        for(int i = 0; i < 4; i++)
        {
            for(int y = 0; y < 4; y++)
            {
                result[i][y] = new EncodedByte(bytes[i][y]).InverseSBoxValue();
            }
        }
        return new DecryptedMatrix(result);
    }
    public DecryptedMatrix MixedColumns()
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
            result[0][i] = (byte) (EncBytes[0].MultipliedBy14() ^ EncBytes[1].MultipliedBy11() ^ EncBytes[2].MultipliedBy13() ^ EncBytes[3].MultipliedBy9());
            result[1][i] = (byte) (EncBytes[0].MultipliedBy9() ^ EncBytes[1].MultipliedBy14() ^ EncBytes[2].MultipliedBy11() ^ EncBytes[3].MultipliedBy13());
            result[2][i] = (byte) (EncBytes[0].MultipliedBy13() ^ EncBytes[1].MultipliedBy9() ^ EncBytes[2].MultipliedBy14() ^ EncBytes[3].MultipliedBy11());
            result[3][i] = (byte) (EncBytes[0].MultipliedBy11() ^ EncBytes[1].MultipliedBy13() ^ EncBytes[2].MultipliedBy9() ^ EncBytes[3].MultipliedBy14());
        }
        return new DecryptedMatrix(result);
    }
    public DecryptedMatrix Shifted()
    {
        byte[][] newMatrix = new byte[4][4];
        for(int i = 0; i < 4; i++)
        {
            newMatrix[i] = new Row(this.bytes[i]).ShiftedRight(i);
        }
        return new DecryptedMatrix(newMatrix);
    }
    public DecryptedMatrix AddedRoundKey(KeyMatrix keyMatrix)
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
        return new DecryptedMatrix(result);
    }
}
