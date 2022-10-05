CamewaDescwipsion UndetectedCamera(__int64 a1)
{
    CamewaDescwipsion VirtualCamera;
    __int64 v1;
    __int64 v6;
    __int64 v7;
    __int64 v8;
    v1 = read<__int64>(Localplayer + 0xd0);
    __int64 v9 = read<__int64>(v1 + 0x10);

    VirtualCamera.FieldOfView = 80.f / (float)((float)read<double>(v9 + 0x680) / 1.19f);//0x680


    VirtualCamera.Rotation.x = read<double>(v9 + 0x7D0);
    VirtualCamera.Rotation.y = read<double>(a1 + 0x148);


    uint64_t VSPointerLc = read<uint64_t>(Uworld + 0x100);
    VirtualCamera.Location = read<Vector3>(VSPointerLc);

    return VirtualCamera;

}
FTransform GetBoneIndex(DWORD_PTR mesh, int index)
{
    DWORD_PTR bonearray;
    bonearray = read<DWORD_PTR>(mesh + 0x5a0);
    if (bonearray == NULL)
    {
        bonearray = read<DWORD_PTR>(mesh + 0x5a0 + 0x10);
    }
    return read<FTransform>(bonearray + (index * 0x60));
}
char* v3; // rdi
__int64 v5; // rsi
char result; // al
int v7; // ecx
char v8; // al
v7 = 17;
v3 = buff;
v5 = (unsigned int)nameLength;
do
{
    v8 = *v3 - v7;
    v7 += 0x1F0B;
    result = ~v8;
    *v3++ = result;
    --v5;
} while (v5);