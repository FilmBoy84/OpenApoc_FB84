#pragma once

#include "game/state/tileview/tileobject.h"
#include "library/sp.h"
#include "library/vec.h"

namespace OpenApoc
{

class Vehicle;
class BattleUnit;
class BattleItem;

class TileObjectShadow : public TileObject
{
  public:
	void draw(Renderer &r, TileTransform &transform, Vec2<float> screenPosition, TileViewMode mode,
	          int, bool, bool) override;
	~TileObjectShadow() override;
	void setPosition(Vec3<float> newPosition) override;
	Vec3<float> getPosition() const override;
	void addToDrawnTiles(Tile *tile) override;

  private:
	friend class TileMap;
	wp<Vehicle> ownerVehicle;
	wp<BattleUnit> ownerBattleUnit;
	wp<BattleItem> ownerBattleItem;
	TileObjectShadow(TileMap &map, sp<Vehicle> owner);
	TileObjectShadow(TileMap &map, sp<BattleUnit> owner);
	TileObjectShadow(TileMap &map, sp<BattleItem> item);
	Vec3<float> shadowPosition;
	bool fellOffTheBottomOfTheMap;
};

} // namespace OpenApoc
