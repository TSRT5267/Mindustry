#include "framework.h"



ObTileMap::ObTileMap()
{
    SafeRelease(vertexBuffer);
    SafeDeleteArray(vertices);
    for (int i = 0; i < 4; i++)
        SafeDelete(tileImages[i]);

    tileSize.x = 50;
    tileSize.y = 50;
    file = "map1.txt";
    scale = Vector2(32.0f, 32.0f);
    tileImages[0] = new ObImage(L"ground/metal_floor.png");
    tileImages[0]->maxFrame = Int2(1, 1);
    tileImages[1] = new ObImage(L"environment/ore_copper.png");
    tileImages[1]->maxFrame = Int2(1, 1);
    tileImages[2] = nullptr;
    tileImages[3] = nullptr;

    ResizeTile(tileSize);
}

ObTileMap::~ObTileMap()
{
    SafeRelease(vertexBuffer);
    SafeDeleteArray(vertices);
    for (int i = 0; i < 4; i++)
        SafeDelete(tileImages[i]);
}

void ObTileMap::Render()
{
    if (!isVisible)return;
    GameObject::Render();

    for (int i = 0; i < 4; i++)
    {
        if (tileImages[i])
        {
            D3D->GetDC()->PSSetShaderResources(i, 1, &tileImages[i]->SRV);
            D3D->GetDC()->PSSetSamplers(i, 1, &tileImages[i]->sampler);
        }
    }

    tileMapShader->Set();

    UINT stride = sizeof(VertexTile);
    UINT offset = 0;

    D3D->GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    D3D->GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    D3D->GetDC()->Draw(tileSize.x * tileSize.y * 6, 0);
}

void ObTileMap::SetTile(Int2 TileIdx, Int2 FrameIdx, int ImgIdx, int TileState, Color color)
{
    int tileIdx = tileSize.x * TileIdx.y + TileIdx.x;
    vertices[tileIdx * 6 + 0].uv.x = FrameIdx.x / (float)tileImages[ImgIdx]->maxFrame.x;
    vertices[tileIdx * 6 + 1].uv.x = FrameIdx.x / (float)tileImages[ImgIdx]->maxFrame.x;
    vertices[tileIdx * 6 + 5].uv.x = FrameIdx.x / (float)tileImages[ImgIdx]->maxFrame.x;


    vertices[tileIdx * 6 + 2].uv.x = (FrameIdx.x + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.x;
    vertices[tileIdx * 6 + 3].uv.x = (FrameIdx.x + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.x;
    vertices[tileIdx * 6 + 4].uv.x = (FrameIdx.x + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.x;

    vertices[tileIdx * 6 + 3].uv.y = FrameIdx.y / (float)tileImages[ImgIdx]->maxFrame.y;
    vertices[tileIdx * 6 + 1].uv.y = FrameIdx.y / (float)tileImages[ImgIdx]->maxFrame.y;
    vertices[tileIdx * 6 + 5].uv.y = FrameIdx.y / (float)tileImages[ImgIdx]->maxFrame.y;

    vertices[tileIdx * 6 + 2].uv.y = (FrameIdx.y + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.y;
    vertices[tileIdx * 6 + 0].uv.y = (FrameIdx.y + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.y;
    vertices[tileIdx * 6 + 4].uv.y = (FrameIdx.y + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.y;

    for (int i = 0; i < 6; i++)
    {
        vertices[tileIdx * 6 + i].tileMapIdx = ImgIdx;
        vertices[tileIdx * 6 + i].color = color;
        vertices[tileIdx * 6 + i].tileState = TileState;
    }


    D3D->GetDC()->UpdateSubresource
    (vertexBuffer, 0, NULL, vertices, 0, 0);
}

void ObTileMap::SetTile2(Int2 TileIdx, Int2 FrameIdx, int ImgIdx, int TileState, Color color)
{
    for (int i = 0;i < 2;i++)
    {
        for (int j = 0;j < 2;j++)
        {
            int tileIdx = tileSize.x * (TileIdx.y-i) + (TileIdx.x+j);
            vertices[tileIdx * 6 + 0].uv.x = (FrameIdx.x+j) / (float)tileImages[ImgIdx]->maxFrame.x;
            vertices[tileIdx * 6 + 1].uv.x = (FrameIdx.x+j) / (float)tileImages[ImgIdx]->maxFrame.x;
            vertices[tileIdx * 6 + 5].uv.x = (FrameIdx.x+j) / (float)tileImages[ImgIdx]->maxFrame.x;

            vertices[tileIdx * 6 + 2].uv.x = (FrameIdx.x + 1.0f+j) / (float)tileImages[ImgIdx]->maxFrame.x;
            vertices[tileIdx * 6 + 3].uv.x = (FrameIdx.x + 1.0f+j) / (float)tileImages[ImgIdx]->maxFrame.x;
            vertices[tileIdx * 6 + 4].uv.x = (FrameIdx.x + 1.0f+j) / (float)tileImages[ImgIdx]->maxFrame.x;
             
            vertices[tileIdx * 6 + 3].uv.y = (FrameIdx.y-i) / (float)tileImages[ImgIdx]->maxFrame.y;
            vertices[tileIdx * 6 + 1].uv.y = (FrameIdx.y-i) / (float)tileImages[ImgIdx]->maxFrame.y;
            vertices[tileIdx * 6 + 5].uv.y = (FrameIdx.y-i) / (float)tileImages[ImgIdx]->maxFrame.y;

            vertices[tileIdx * 6 + 2].uv.y = (FrameIdx.y + 1.0f-i) / (float)tileImages[ImgIdx]->maxFrame.y;
            vertices[tileIdx * 6 + 0].uv.y = (FrameIdx.y + 1.0f-i) / (float)tileImages[ImgIdx]->maxFrame.y;
            vertices[tileIdx * 6 + 4].uv.y = (FrameIdx.y + 1.0f-i) / (float)tileImages[ImgIdx]->maxFrame.y;

            for (int k = 0; k < 6; k++)
            {
                vertices[tileIdx * 6 + k].tileMapIdx = ImgIdx;
                vertices[tileIdx * 6 + k].color = color;
                vertices[tileIdx * 6 + k].tileState = TileState;
            }
        }
    }
    


    D3D->GetDC()->UpdateSubresource
    (vertexBuffer, 0, NULL, vertices, 0, 0);
}

int ObTileMap::GetTileState(Int2 TileIdx)
{
    int tileIdx = tileSize.x * TileIdx.y + TileIdx.x;
    return vertices[tileIdx * 6].tileState;
}

int ObTileMap::GetTileState(Vector2 WorldPos)
{
    Int2 plIdx;
    if (WorldPosToTileIdx(WorldPos, plIdx))
    {
        return GetTileState(plIdx);
    }

    return -1;
}

Color ObTileMap::GetTileColor(Int2 TileIdx)
{
    int tileIdx = tileSize.x * TileIdx.y + TileIdx.x;
    
    return vertices[tileIdx * 6 ].color ;
}

int ObTileMap::GetTileIdx(Int2 TileIdx)
{
    int tileIdx = tileSize.x * TileIdx.y + TileIdx.x;

    return  vertices[tileIdx * 6 ].tileMapIdx  ;
}

Vector2 ObTileMap::GetTileFrame(Int2 TileIdx)
{
    int tileIdx = tileSize.x * TileIdx.y + TileIdx.x;
    Vector2 frame;
    frame.x= vertices[tileIdx * 6 + 2].uv.x;
    frame.y= vertices[tileIdx * 6 + 2].uv.y;
    
    return frame;
}

Vector2 ObTileMap::GetTilePosition(Int2 TileIdx)
{
    int tileIdx = tileSize.x * TileIdx.y + TileIdx.x;
    return Vector2(vertices[tileIdx * 6].position.x, vertices[tileIdx * 6].position.y);
}

void ObTileMap::Update()
{
    GameObject::Update();







}


bool ObTileMap::WorldPosToTileIdx(Vector2 WPos, Int2& TileIdx)
{
    WPos -= GetWorldPos();
    Vector2 tileCoord;
    tileCoord.x = WPos.x / scale.x;
    tileCoord.y = WPos.y / scale.y;
    if ((tileCoord.x < 0) or (tileCoord.y < 0) or
        (tileCoord.x >= tileSize.x) or (tileCoord.y >= tileSize.y))
    {
        return false;
    }
    TileIdx.x = tileCoord.x;
    TileIdx.y = tileCoord.y;
    return true;
}

void ObTileMap::ResizeTile(Int2 TileSize)
{
    VertexTile* Vertices = new VertexTile[TileSize.x * TileSize.y * 6];
    //Init
    for (int i = 0; i < TileSize.y; i++)
    {

        //가로
        for (int j = 0; j < TileSize.x; j++)
        {
            //타일좌표 ( tileSize.x * y좌표 + x좌표)
            //꼭지점 좌표 ( tileSize.x * y좌표 + x좌표) * 6
            int tileIdx = TileSize.x * i + j;
            //0
            Vertices[tileIdx * 6].position.x = 0.0f + j;
            Vertices[tileIdx * 6].position.y = 0.0f + i;
            Vertices[tileIdx * 6].uv = Vector2(0.0f, 1.0f);
            //1                             
            Vertices[tileIdx * 6 + 1].position.x = 0.0f + j;
            Vertices[tileIdx * 6 + 1].position.y = 1.0f + i;
            Vertices[tileIdx * 6 + 1].uv = Vector2(0.0f, 0.0f);
            //2                             
            Vertices[tileIdx * 6 + 2].position.x = 1.0f + j;
            Vertices[tileIdx * 6 + 2].position.y = 0.0f + i;
            Vertices[tileIdx * 6 + 2].uv = Vector2(1.0f, 1.0f);
            //3
            Vertices[tileIdx * 6 + 3].position.x = 1.0f + j;
            Vertices[tileIdx * 6 + 3].position.y = 1.0f + i;
            Vertices[tileIdx * 6 + 3].uv = Vector2(1.0f, 0.0f);
            //4
            Vertices[tileIdx * 6 + 4].position.x = 1.0f + j;
            Vertices[tileIdx * 6 + 4].position.y = 0.0f + i;
            Vertices[tileIdx * 6 + 4].uv = Vector2(1.0f, 1.0f);
            //5
            Vertices[tileIdx * 6 + 5].position.x = 0.0f + j;
            Vertices[tileIdx * 6 + 5].position.y = 1.0f + i;
            Vertices[tileIdx * 6 + 5].uv = Vector2(0.0f, 0.0f);
        }
    }

    //Copy
    if (vertices)
    {
        Int2 Min = Int2(min(TileSize.x, tileSize.x), min(TileSize.y, tileSize.y));
        for (int i = 0; i < Min.y; i++)
        {
            for (int j = 0; j < Min.x; j++)
            {
                int SrcIdx = tileSize.x * i + j;
                int DestIdx = TileSize.x * i + j;
                for (int k = 0; k < 6; k++)
                {
                    Vertices[DestIdx * 6 + k] = vertices[SrcIdx * 6 + k];
                }
            }
        }
    }

    SafeDeleteArray(vertices);
    vertices = Vertices;
    tileSize = TileSize;
    SafeRelease(vertexBuffer);
    //CreateVertexBuffer
    {
        D3D11_BUFFER_DESC desc;
        desc = { 0 };
        desc.Usage = D3D11_USAGE_DEFAULT;
        desc.ByteWidth = sizeof(VertexTile) * tileSize.x * tileSize.y * 6;
        desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        D3D11_SUBRESOURCE_DATA data = { 0 };
        data.pSysMem = vertices;
        HRESULT hr = D3D->GetDevice()->CreateBuffer(&desc, &data, &vertexBuffer);
        Check(hr);
    }
}

void ObTileMap::Save()
{
    ofstream fout;
    string path = "../Contents/TileMap/" + file;
    fout.open(path.c_str(), ios::out);
    if (fout.is_open())
    {
        for (int i = 0; i < 4; i++)
        {
            fout << i << " ";
            if (tileImages[i])
            {
                string imgFile = "";
                imgFile.assign(tileImages[i]->file.begin(), tileImages[i]->file.end());
                fout << imgFile << " ";
                fout << tileImages[i]->maxFrame.x << " " << tileImages[i]->maxFrame.y << endl;
            }
            else
            {
                fout << "N" << endl;
            }
        }
        fout << "TileSize " << tileSize.x << " " << tileSize.y << endl;
        fout << "TileScale " << scale.x << " " << scale.y << endl;
        fout << "TilePosition " << GetWorldPos().x << " " << GetWorldPos().y << endl;

        for (int i = 0; i < tileSize.y; i++)
        {
            //가로
            for (int j = 0; j < tileSize.x; j++)
            {
                int tileIdx = tileSize.x * i + j;
                fout << j << " " << i << " "
                    << vertices[tileIdx * 6 + 1].uv.x << " " << vertices[tileIdx * 6 + 1].uv.y << " "
                    << vertices[tileIdx * 6 + 2].uv.x << " " << vertices[tileIdx * 6 + 2].uv.y << " "
                    << vertices[tileIdx * 6].color.x << " " << vertices[tileIdx * 6].color.y << " "
                    << vertices[tileIdx * 6].color.z << " " << vertices[tileIdx * 6].color.w << " "
                    << vertices[tileIdx * 6].tileMapIdx << " " << vertices[tileIdx * 6].tileState << endl;
            }
        }
        fout.close();
    }
}

void ObTileMap::Load()
{
    ifstream fin;
    string path = "../Contents/TileMap/" + file;
    fin.open(path.c_str(), ios::in);
    string temp;
    if (fin.is_open())
    {
        for (int i = 0; i < 4; i++)
        {
            SafeDelete(tileImages[i]);
            int idx; string Imgfile;
            fin >> idx;
            fin >> Imgfile;
            if (Imgfile != "N")
            {
                wstring wImgFile = L"";
                wImgFile.assign(Imgfile.begin(), Imgfile.end());
                tileImages[i] = new ObImage(wImgFile);
                fin >> tileImages[i]->maxFrame.x >> tileImages[i]->maxFrame.y;
            }
        }
        Int2 TileSize;
        fin >> temp >> TileSize.x >> TileSize.y;
        ResizeTile(TileSize);
        fin >> temp >> scale.x >> scale.y;
        Vector2 pos;
        fin >> temp >> pos.x >> pos.y;
        SetWorldPos(pos);

        for (int i = 0; i < tileSize.y; i++)
        {
            //가로
            for (int j = 0; j < tileSize.x; j++)
            {
                int temp; Vector2 MinUV, MaxUV; Color color; float tileMapIdx, tileMapState;
                fin >> temp >> temp >> MinUV.x >> MinUV.y >> MaxUV.x >> MaxUV.y
                    >> color.x >> color.y >> color.z >> color.w >> tileMapIdx >> tileMapState;

                int tileIdx = tileSize.x * i + j;

                vertices[tileIdx * 6].uv = Vector2(MinUV.x, MaxUV.y);
                vertices[tileIdx * 6 + 1].uv = Vector2(MinUV.x, MinUV.y);
                vertices[tileIdx * 6 + 2].uv = Vector2(MaxUV.x, MaxUV.y);
                vertices[tileIdx * 6 + 3].uv = Vector2(MaxUV.x, MinUV.y);
                vertices[tileIdx * 6 + 4].uv = Vector2(MaxUV.x, MaxUV.y);
                vertices[tileIdx * 6 + 5].uv = Vector2(MinUV.x, MinUV.y);
                for (int k = 0; k < 6; k++)
                {
                    vertices[tileIdx * 6 + k].color = color;
                    vertices[tileIdx * 6 + k].tileMapIdx = tileMapIdx;
                    vertices[tileIdx * 6 + k].tileState = tileMapState;
                }
            }
        }
        D3D->GetDC()->UpdateSubresource
        (vertexBuffer, 0, NULL, vertices, 0, 0);

        fin.close();
    }
}



void Tile::ClearCost()
{
    //비용을 무한값으로 초기화
    F = G = H = INT_MAX;
    P = nullptr;
    isFind = false;
}

void Tile::ClacH(Int2 DestIdx)
{
    //너의 목적지까지의 예상비용을 계산해라
    int tempX = abs(idx.x - DestIdx.x) * 10;
    int tempY = abs(idx.y - DestIdx.y) * 10;

    H = tempX + tempY;
}

void Tile::ClacF()
{
    F = G + H;
}


void ObTileMap::CreateTileCost()
{
    for (int i = 0; i < Tiles.size(); i++)
    {
        Tiles[i].clear();
    }
    Tiles.clear();


    Tiles.resize(tileSize.x);
    for (int i = 0; i < Tiles.size(); i++)
    {
        Tiles[i].resize(tileSize.y);
    }


    Vector2 half = scale * 0.5f;
    Update();
    for (int i = 0; i < tileSize.x; i++)
    {
        for (int j = 0; j < tileSize.y; j++)
        {
            Tiles[i][j].idx = Int2(i, j);
            Tiles[i][j].state = GetTileState(Tiles[i][j].idx);
            Tiles[i][j].Pos.x = i * scale.x + GetWorldPos().x + half.x;
            Tiles[i][j].Pos.y = j * scale.y + GetWorldPos().y + half.y;
        }
    }
}

bool ObTileMap::PathFinding(Int2 sour, Int2 dest, OUT vector<Tile*>& way)
{

    //둘중에 하나가 벽이면 갈 수 있는길이 없다.
    if (Tiles[dest.x][dest.y].state == TILE_WALL ||
        Tiles[sour.x][sour.y].state == TILE_WALL)
    {
        return false;
    }
    //기존에 있던 길은 전부 비운다.
    way.clear();
    //출발지 목적지 같으면
    if (sour == dest)
    {
        return false;//제자리 멈추기
    }



    //타일 비용 초기화
    for (int i = 0; i < tileSize.x; i++)
    {
        for (int j = 0; j < tileSize.y; j++)
        {
            Tiles[i][j].ClearCost();
        }
    }
    //우선순위 큐
    
    //F값을 가지고 정렬해주는 리스트
    priority_queue<PTile, vector<PTile>, compare> List;
    //priority_queue<Tile*> List;
    //Tile* a, *b;
    //a > b;

    //리스트에 출발지를 추가
    Tile* pTemp = &Tiles[sour.x][sour.y];
    pTemp->G = 0;       //출발지 현재비용은 0
    pTemp->ClacH(dest); //목적지까지 예상비용 만들기
    pTemp->ClacF();     //총예상비용 만들기
    List.push({ pTemp ,pTemp->F });

    //도착점까지 비용이 생길때 까지 반복
    while (1)
    {
        //꺼내야될 F값이 더이상 없을때
        if (List.empty())
        {
            return false;
        }

        //탐색노드 받아오기
        PTile Temp = List.top();
        //탐색목록에서 제외
        Temp.first->isFind = true;
        //맨윗값 빼버리기
        List.pop();

        //맨윗값이 도착점이면 종료(길찾기 종료조건)
        if (Temp.first->idx == dest)
        {
            break;
        }

        //인접 타일 비용검사
        vector<Int2> LoopIdx;

        //왼쪽타일이 존재할때
        if (Temp.first->idx.x > 0)
        {
            LoopIdx.push_back(Int2(Temp.first->idx.x - 1,
                Temp.first->idx.y));
        }
        //위쪽타일이 존재할때
        if (Temp.first->idx.y > 0)
        {
            LoopIdx.push_back(Int2(Temp.first->idx.x,
                Temp.first->idx.y - 1));
        }
        //오른쪽타일이 존재할때
        if (Temp.first->idx.x < tileSize.x - 1)
        {
            LoopIdx.push_back(Int2(Temp.first->idx.x + 1,
                Temp.first->idx.y));
        }
        //아래쪽타일이 존재할때
        if (Temp.first->idx.y < tileSize.y - 1)
        {
            LoopIdx.push_back(Int2(Temp.first->idx.x,
                Temp.first->idx.y + 1));
        }
        //상하좌우타일 비용검사
        for (int i = 0; i < LoopIdx.size(); i++)
        {
            Tile* loop =
                &Tiles[LoopIdx[i].x][LoopIdx[i].y];
            //벽이 아닐때
            if (loop->state != TILE_WALL)
            {
                //예상비용 만들기
                loop->ClacH(dest);
                //현재 가지고있는 비용이 클때
                if (loop->G > Temp.first->G + 10)
                {
                    //비용갱신
                    loop->G = Temp.first->G + 10;
                    loop->ClacF();
                    //누구로부터 갱신인지 표시
                    loop->P = Temp.first;
                    //이 타일이 찾은적 없던 타일이면 리스트에 추가
                    if (!loop->isFind)
                    {
                        List.push({ loop,loop->F });
                    }
                }
            }
        }
        LoopIdx.clear();

        //대각선4개 




    }
    //도착지가 설정이 되었을때

    Tile* p = &Tiles[dest.x][dest.y];
    //dest 4,1 -> 4,2 -> 4,3 -> 3,3 ->2,3-> 1,3 ->
    while (1)
    {
        way.push_back(p);
        p = p->P;
        if (p == nullptr)
        {
            break;
        }
    }
    return true;
}

bool ObTileMap::PathFinding(Vector2 sour, Vector2 dest, OUT vector<Tile*>& way)
{
    Int2 sourIdx , destIdx;
    if (WorldPosToTileIdx(sour, sourIdx)and
        WorldPosToTileIdx(dest, destIdx))
    {
        return PathFinding(sourIdx, destIdx, way);
    }

    return false;
}


