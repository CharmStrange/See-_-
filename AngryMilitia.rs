use rand::Rng;

const ROW: usize = 9;
const COLUMN: usize = 9;

#[derive(Clone, Copy)]
struct Farmland {
    fertility: u8,
    moisture: u8,
    light: u8,
    scale: u8,
    condition: i8,
}

impl Farmland {
    fn new() -> Self {
        Farmland {
            fertility: 1,
            moisture: 1,
            light: 1,
            scale: 1,
            condition: 0,
        }
    }
}

fn initialize_farmland() -> [[Farmland; COLUMN]; ROW] {
    let mut farm = [[Farmland::new(); COLUMN]; ROW];
    for row in 0..ROW {
        for col in 0..COLUMN {
            farm[row][col].condition =
                (farm[row][col].fertility as i8 + farm[row][col].moisture as i8 + farm[row][col].light as i8 + farm[row][col].scale as i8) / 4;
        }
    }
    farm
}

fn random_initialize_farmland() -> [[Farmland; COLUMN]; ROW] {
    let mut rng = rand::thread_rng();
    let mut farm = [[Farmland::new(); COLUMN]; ROW];
    for row in 0..ROW {
        for col in 0..COLUMN {
            farm[row][col].fertility = rng.gen_range(0..10);
            farm[row][col].moisture = rng.gen_range(0..10);
            farm[row][col].light = rng.gen_range(0..10);
            farm[row][col].scale = rng.gen_range(0..10);
            farm[row][col].condition =
                (farm[row][col].fertility as i8 + farm[row][col].moisture as i8 + farm[row][col].light as i8 + farm[row][col].scale as i8) / 4;
        }
    }
    farm
}

fn update_neighbour_cells(farm: &mut [[Farmland; COLUMN]; ROW], row: usize, col: usize) {
    if row > 0 {
        farm[row - 1][col].fertility = farm[row - 1][col].fertility.saturating_sub(1);
        farm[row - 1][col].moisture = farm[row - 1][col].moisture.saturating_sub(1);
        farm[row - 1][col].light = farm[row - 1][col].light.saturating_sub(1);
        farm[row - 1][col].scale = farm[row - 1][col].scale.saturating_sub(1);
    }
    if row < ROW - 1 {
        farm[row + 1][col].fertility = farm[row + 1][col].fertility.saturating_sub(1);
        farm[row + 1][col].moisture = farm[row + 1][col].moisture.saturating_sub(1);
        farm[row + 1][col].light = farm[row + 1][col].light.saturating_sub(1);
        farm[row + 1][col].scale = farm[row + 1][col].scale.saturating_sub(1);
    }
    if col > 0 {
        farm[row][col - 1].fertility = farm[row][col - 1].fertility.saturating_sub(1);
        farm[row][col - 1].moisture = farm[row][col - 1].moisture.saturating_sub(1);
        farm[row][col - 1].light = farm[row][col - 1].light.saturating_sub(1);
        farm[row][col - 1].scale = farm[row][col - 1].scale.saturating_sub(1);
    }
    if col < COLUMN - 1 {
        farm[row][col + 1].fertility = farm[row][col + 1].fertility.saturating_sub(1);
        farm[row][col + 1].moisture = farm[row][col + 1].moisture.saturating_sub(1);
        farm[row][col + 1].light = farm[row][col + 1].light.saturating_sub(1);
        farm[row][col + 1].scale = farm[row][col + 1].scale.saturating_sub(1);
    }
}

fn is_available(farm: &mut [[Farmland; COLUMN]; ROW]) -> usize {
    let mut condition = 0;

    for row in 0..ROW {
        for col in 0..COLUMN {
            let current_land = farm[row][col];
            if current_land.condition >= 4 {
                condition += 1;
                update_neighbour_cells(farm, row, col);
            }
        }
    }

    condition
}

fn main() {
    if ROW != COLUMN {
        std::process::exit(1);
    }

    // let mut farm = initialize_farmland();
    let mut farm = random_initialize_farmland();

    let available = is_available(&mut farm);
    println!("Number of available farmlands: {}", available);
}
