import java.nio.charset.StandardCharsets;
public class Main {
    public static void main(String[] args) {
          ByteFile file = new ByteFile(args[1].getBytes(StandardCharsets.UTF_8));
          byte[] firstKeyBytes = args[2].getBytes();

          if(firstKeyBytes.length != 16)
          {
              System.out.println("Key needs to be 16-bytes long");
              throw new RuntimeException();
          }

          byte[][] firstKey = new byte[4][4];
          for (int i = 0; i < 16; i++)
          {
              firstKey[i/4][i%4] = firstKeyBytes[i];
          }

                //Generate whole set of keys.
          KeyMatrix[] keys = new KeyMatrix[11];
          keys[0] = new KeyMatrix(firstKey);
          for(int i = 1; i < 11; i++)
          {
              keys[i] = keys[i-1].NextMatrix();
          }

                //Either encrypt or decrypt the message. Throw error if not correctly specified.
                //I've encountered an issue where the array encoded back into string gives a wrong result when decrypted,
                //thus I made the program also turn it back to confirm it isn't caused by internal algorithm.
          if(args[0].compareToIgnoreCase("e") == 0)
          {
              byte[] encrypted = Encrypted(keys, file);
              System.out.println(new String(encrypted, StandardCharsets.UTF_8));
              byte[] decrypted = Decrypted(keys, new ByteFile(encrypted));
              System.out.println(new String(decrypted, StandardCharsets.UTF_8));
          } else if(args[0].compareToIgnoreCase("d") == 0)
          {
              byte[] decrypted = Decrypted(keys, file);
              System.out.println(new String(decrypted, StandardCharsets.UTF_8));
              byte[] encrypted = Encrypted(keys, new ByteFile(decrypted));
              System.out.println(new String(encrypted, StandardCharsets.UTF_8));
          } else
          {
              System.out.println("Incorrect operation. First argument needs to be either \"e\" or \"d\".");
              throw new RuntimeException();
          }
    }

    public static byte[] Encrypted(KeyMatrix[] keys, ByteFile file) {
        int blockCount = file.BlockCount();
        byte[] result = new byte[blockCount*16];
            //Loop runs through all 16-byte segments of input
        for(int i = 0; i < blockCount; i++)
        {
            EncryptedMatrix matrix = new EncryptedMatrix(file.Block(i));

                //Here's where the actual encryption happens.
            matrix = matrix.AddedRoundKey(keys[0]);
            for(int y = 1; y <= 9; y++)
            {
                matrix = matrix.Substituted();
                matrix = matrix.Shifted();
                matrix = matrix.MixedColumns();
                matrix = matrix.AddedRoundKey(keys[y]);
            }
            matrix = matrix.Substituted();
            matrix = matrix.Shifted();
            matrix = matrix.AddedRoundKey(keys[10]);

                //Copy the contents of current block to final result array.
            System.arraycopy(matrix.ByteArray(), 0, result, i*16, 16);
        }
        return result;
    }
    public static byte[] Decrypted(KeyMatrix[] keys, ByteFile file) {
        int blockCount = file.BlockCount();
        byte[] result = new byte[blockCount*16];
        //Loop runs through all 16-byte segments of input
        for(int i = 0; i < blockCount; i++)
        {
            DecryptedMatrix matrix = new DecryptedMatrix(file.Block(i));

            matrix = matrix.AddedRoundKey(keys[10]);
            matrix = matrix.Shifted();
            matrix = matrix.Substituted();
            for(int y = 1; y <= 9; y++)
            {
                matrix = matrix.AddedRoundKey(keys[10-y]);
                matrix = matrix.MixedColumns();
                matrix = matrix.Shifted();
                matrix = matrix.Substituted();
            }
            matrix = matrix.AddedRoundKey(keys[0]);

                //Copy the contents of current block to final result array.
            System.arraycopy(matrix.ByteArray(), 0, result, i*16, 16);
        }
        return result;
    }
}