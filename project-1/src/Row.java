public class Row {
    private final byte[] row;
    public Row(byte[] input)
    {
        row = input;
    }
    public byte[] ShiftedLeft(int shift)
    {
        byte[] newRow = new byte[this.row.length];
        for(int i = 0; i < this.row.length; i++)
        {
            newRow[i] = this.row[(i+shift)%this.row.length];
        }
        return newRow;
    }

    public byte[] ShiftedRight(int shift)
    {
        byte[] newRow = new byte[this.row.length];
        for(int i = 0; i < this.row.length; i++)
        {
            newRow[(i+shift)%this.row.length] = this.row[i];
        }
        return newRow;
    }
}
