#include "game/city/buildingtile.h"
#include "framework/palette.h"
#include "game/apocresources/pck.h"
#include "framework/framework.h"
#include "game/tileview/voxel.h"
#include "game/apocresources/loftemps.h"

namespace OpenApoc
{

BuildingTile::BuildingTile(TileMap &map, BuildingTileDef &tileDef, Vec3<int> pos,
                           sp<Building> building)
    : TileObject(map, pos),
      TileObjectSprite(map, pos, tileDef.getSprite(), tileDef.getStrategySprite()),
      TileObjectCollidable(map, pos, {32, 32, 16}, tileDef.getVoxelMap()), pos(pos),
      building(building), tileDef(tileDef)
{
}

BuildingTile::~BuildingTile() {}

}; // namesapce OpenApoc
