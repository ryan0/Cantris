local Wolf = {}

function Wolf.new(pos)
    local self = {}
    self.id = "Wolf"
    self.Renderable = {
        zValue = 0
    }
    self.Animator = {
        position = {-3.7, -5.2},
        animations = {
            {"Standing", "hound.lua"},
            {"Walking", "hound.lua"},
            {"Running", "hound.lua"}
        }
    }
    self.Spatial = {
        position = {0, 0},
        origin = {0, 0}
    }
    self.Physical = {
        b2BodyDef = {
            position = pos,
            fixedRotation = true;
            type = "b2_dynamicBody"
        },
        b2FixtureDef = {
            density = 1.0,
            friction = .2,
            restitution = .0,
            b2PolygonShape = {
                setAsBox = {2.2, 1.5}
            }
        }
    }
    self.Scriptable = {
        {
            script = "wolfControl"
        }
    }
    return self
end

return Wolf

