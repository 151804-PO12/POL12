public interface CipherMatrix {
    byte[] ByteArray();
    CipherMatrix Substituted();
    CipherMatrix MixedColumns();
    CipherMatrix Shifted();
    CipherMatrix AddedRoundKey(KeyMatrix key);
}
