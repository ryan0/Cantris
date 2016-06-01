local Player = {}

function Player.new()
    local self = {}
    self.Renderable = {
        zValue = 0
    }
    self.Animator = {
        position = {-7.5, -16.5},
        animations = {
            {"Walking", "player.lua"},
            {"Running", "player.lua", offset = {-13, 0}, frametime = 1/10},
            {"Jumping", "player.lua", offset = {-13, 0}},
            {"Standing", "player.lua"}
        }
    }
    self.Spatial = {
        position = {0, 0},
        origin = {0, 0}
    }
    self.Physical = {
        b2BodyDef = {
            position = {0, 0},
            fixedRotation = true;
            type = "b2_dynamicBody"
        },
        b2FixtureDef = {
            density = 1.0,
            friction = 0.0,
            restitution = 0.0,
            b2PolygonShape = {
                setAsBox = {0.8, 1.9}
            }
        }
    }
    self.Scriptable = {
        {
            script = "playerControl"
        }
    }
    return self
end

return Player